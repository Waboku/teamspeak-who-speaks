'' Files2AtmelProject
'' Converts a source tree with a Makefile to an Atmel Studio 7 .cproj project file
'' When opened with Atmel Studio 7 it will prettify the XML of the cproj file,
'' add missing defaults and create an .atsln file
''
'' Verion 0.1 (BETA)

' Global objects
Set objFso = CreateObject("Scripting.FileSystemObject")
Set searchdirs = CreateObject("System.Collections.ArrayList")
Set includedirs = CreateObject("System.Collections.ArrayList")
Set includefiles = CreateObject("System.Collections.ArrayList")
Set fileextensions = CreateObject("System.Collections.ArrayList")
Set objShellApp = CreateObject("Shell.Application")
Set objShell = CreateObject("Wscript.Shell")

'Global variables File searching
Dim searchdirs
Dim projectpath
Dim includedirs
Dim includefiles
Dim fileextensions
Dim objShell

'Global variables XML/cproj
Dim toolchainname
Dim projectguid
Dim device
Dim outputtype
Dim language
Dim outputfilename
Dim outputfileextension
Dim outputdirectory
Dim assemblyname
Dim name
Dim fullname
Dim rootnamespace
Dim makefile

'Makefile search string (for the project name)
Dim makefilesearch

'Search directories
searchdirs.Add "src"
searchdirs.Add "include"

'File extensions to search for
fileextensions.Add "h"
fileextensions.Add "c"

'XML/cproj variables
toolchainname = "com.Atmel.ARMGCC.C"
projectguid = CreateGUID()
device = "ATSAMD21E17A"
outputtype = "Executable"
language = "C"
outputfilename = "$(MSBuildProjectName)"
outputfileextension = ".elf"
outputdirectory = "$(MSBuildProjectDirectory)"

'Should be ok for Cmake generated Makefiles
makefilesearch = "# Target rules for targets named "

'The current path so we can determine the relative path
projectpath = objFso.GetAbsolutePathName(".\")


Function PrintFileList
  For Each file In includefiles
    WScript.Echo file
  Next
End Function

Function PrintDirList
  For Each dir In includedirs
    WScript.Echo dir
  Next
End Function

Function ConvertToRelativePath(path)
    ConvertToRelativePath = Replace(path, projectpath+"\", "")
End Function

Function AddToFileList(path)
    'WScript.Echo "AddFile" + path
    includefiles.Add(path)
    AddToDirList(objFso.GetParentFolderName(path))
End Function

Function AddToDirList(path)
    'Path to the file, need to get the parents
    cp = path
    Do While Len(cp)>0
        If (NOT includedirs.Contains(cp)) Then
            'WScript.Echo "AddFolder: " + cp
            includedirs.Add(cp)
        End If
            cp = objFso.GetParentFolderName(cp)
    Loop
End Function

Function TraverseFolders(fldr)
  For Each sf In fldr.SubFolders
    TraverseFolders sf  '<- recurse here
    'WScript.Echo "Folder: ", ConvertToRelativePath(sf)
  Next
  
  For Each file In fldr.Files
    'WScript.Echo "File: ", ConvertToRelativePath(file)
    If fileextensions.Contains(objFso.getextensionname(file)) Then
        'WScript.Echo "File: ", ConvertToRelativePath(file)
        AddToFileList(ConvertToRelativePath(file))
    End If
  Next
End Function

'Find the files and folders needed within the project
Function FindProjectFiles
    For Each searchdir In searchdirs
        'WScript.Echo "# Search directory: ", searchdir
        TraverseFolders objFso.GetFolder(searchdir)
    Next
End Function

Function CreateGUID
  Dim TypeLib
  Set TypeLib = CreateObject("Scriptlet.TypeLib")
  CreateGUID = Mid(TypeLib.Guid, 2, 36)
End Function

'Generates the XML based .cproj
'outfile: The output file name (path) of the cproj
Function GenerateAtmelStudioCproj(outfile)

    Set xmlDoc = CreateObject("Microsoft.XMLDOM")  

    Set objProject = xmlDoc.createElement("Project")  
    objProject.setAttribute "DefaultTargets", "Build"
    objProject.setAttribute "xmlns", "http://schemas.microsoft.com/developer/msbuild/2003"
    objProject.setAttribute "ToolsVersion", "14.0"
    xmlDoc.appendChild objProject  

    Set objPropertyGroup = xmlDoc.createElement("PropertyGroup") 
    objProject.appendChild objPropertyGroup 

    'Project settings: PropertyGroup
    Set objSchemaVersion = xmlDoc.createElement("SchemaVersion")
    objSchemaVersion.Text = "2.0"
    objPropertyGroup.appendChild objSchemaVersion

    Set objProjectVersion = xmlDoc.createElement("ProjectVersion")
    objProjectVersion.Text = "7.0"
    objPropertyGroup.appendChild objProjectVersion

    Set objToolchainName = xmlDoc.createElement("ToolchainName")
    objToolchainName.Text = toolchainname
    objPropertyGroup.appendChild objToolchainName

    Set objProjectGuid = xmlDoc.createElement("ProjectGuid")
    objProjectGuid.Text = projectguid
    objPropertyGroup.appendChild objProjectGuid

    Set objAvrDevice = xmlDoc.createElement("avrdevice")
    objAvrDevice.Text = device
    objPropertyGroup.appendChild objAvrDevice

    Set objOutputType = xmlDoc.createElement("OutputType")
    objOutputType.Text = outputtype
    objPropertyGroup.appendChild objOutputType

    Set objLanguage = xmlDoc.createElement("Language")
    objLanguage.Text = language
    objPropertyGroup.appendChild objLanguage

    Set objOutputFileName = xmlDoc.createElement("OutputFileName")
    objOutputFileName.Text = outputfilename
    objPropertyGroup.appendChild objOutputFileName

    Set objOutputFileExtension = xmlDoc.createElement("OutputFileExtension")
    objOutputFileExtension.Text = outputfileextension
    objPropertyGroup.appendChild objOutputFileExtension

    Set objOutputDirectory = xmlDoc.createElement("OutputDirectory")
    objOutputDirectory.Text = outputdirectory
    objPropertyGroup.appendChild objOutputDirectory

    Set objAssemblyName = xmlDoc.createElement("AssemblyName")
    objAssemblyName.Text = assemblyname
    objPropertyGroup.appendChild objAssemblyName

    Set objName = xmlDoc.createElement("Name")
    objName.Text = name
    objPropertyGroup.appendChild objName

    Set objRootNamespace = xmlDoc.createElement("RootNamespace")
    objRootNamespace.Text = rootnamespace
    objPropertyGroup.appendChild objRootNamespace
    'END project settings


    'Release configuration settings: PropertyGroup Condition=" '$(Configuration)' == 'Release' "
    Set objPropertyGroupRelease = xmlDoc.createElement("PropertyGroup")
    objPropertyGroupRelease.setAttribute "Condition", " '$(Configuration)' == 'Release' "
    objProject.appendChild objPropertyGroupRelease

    'Makefile settings
    Set objUsesExternalMakeFileRelease = xmlDoc.createElement("UsesExternalMakeFile")
    objUsesExternalMakeFileRelease.Text = "True"
    objPropertyGroupRelease.appendChild objUsesExternalMakeFileRelease

    Set objExternalMakeFilePathRelease = xmlDoc.createElement("ExternalMakeFilePath")
    objExternalMakeFilePathRelease.Text = "Makefile"
    objPropertyGroupRelease.appendChild objExternalMakeFilePathRelease

    Set objBuildTargetRelease = xmlDoc.createElement("BuildTarget")
    objBuildTargetRelease.Text = "all -j4"
    objPropertyGroupRelease.appendChild objBuildTargetRelease
    'End Release configuration settings


    'Debug configuration settings: PropertyGroup Condition=" '$(Configuration)' == 'Debug' "
    Set objPropertyGroupDebug = xmlDoc.createElement("PropertyGroup")
    objPropertyGroupDebug.setAttribute "Condition", " '$(Configuration)' == 'Debug' "
    objProject.appendChild objPropertyGroupDebug

    'Makefile settings
    Set objUsesExternalMakeFileDebug = xmlDoc.createElement("UsesExternalMakeFile")
    objUsesExternalMakeFileDebug.Text = "True"
    objPropertyGroupDebug.appendChild objUsesExternalMakeFileDebug

    Set objExternalMakeFilePathDebug = xmlDoc.createElement("ExternalMakeFilePath")
    objExternalMakeFilePathDebug.Text = "Makefile"
    objPropertyGroupDebug.appendChild objExternalMakeFilePathDebug

    Set objBuildTargetDebug = xmlDoc.createElement("BuildTarget")
    objBuildTargetDebug.Text = "all -j4"
    objPropertyGroupDebug.appendChild objBuildTargetDebug
    'End Debug configuration settings


    Set objImport = xmlDoc.createElement("Import")
    objImport.setAttribute "Project", "$(AVRSTUDIO_EXE_PATH)\\Vs\\Compiler.targets"
    objProject.appendChild objImport


    'Items (c,h,dirs): ItemGroup
    Set objItemGroup = xmlDoc.createElement("ItemGroup")
    objProject.appendChild objItemGroup

    'Loop folders
    For Each idir In includedirs
        'WScript.Echo "# Add directory: ", idir
        Set objDir = xmlDoc.createElement("Folder")
        objDir.setAttribute "Include", idir
        objItemGroup.appendChild objDir
    Next

    'Loop files
    For Each ifile In includefiles
        'WScript.Echo "# Add file ", ifile
        Set objFile = xmlDoc.createElement("Compile")
        objFile.setAttribute "Include", ifile
        Set objSubType = xmlDoc.createElement("SubType")
        objSubType.Text = "compile"
        objFile.appendChild objSubType
        objItemGroup.appendChild objFile
    Next

    'Set general XML settings on top of the file
    Set objIntro = xmlDoc.createProcessingInstruction ("xml","version='1.0' encoding='UTF-8'")  
    xmlDoc.insertBefore objIntro,xmlDoc.childNodes(0)  

    'Save the xml cproj file
    xmlDoc.Save outfile
End Function

Function GetMakefileLocation
    makefile = InputBox("Enter Makefile name/location:", "Enter Makefile", "Makefile")
End Function

Function GetProjectName
    projectname = InputBox("Project name not found, enter Project name", "Enter Project name")
End Function

Function FindProjectNameMakefile
    Set objRegEx = New RegExp
    objRegEx.IgnoreCase = True
    objRegEx.Global = True
    objRegEx.Pattern = "(" + makefilesearch + ".*)$"

    Set objMakefile = objFSO.OpenTextFile(makefile)

    Do Until objMakefile.AtEndOfStream
        line = objMakefile.ReadLine
        Set colMatches = objRegEx.Execute(line)
        If colMatches.Count > 0 Then
            namefull = Replace(colMatches(0), makefilesearch, "")
            parts = split(namefull, ".")
            name = parts(0)
            Msgbox "Using project name: " + name, vbSystemModal
            objMakefile.Close
            Exit Function
        End If
    Loop
    
    GetProjectName()
    objMakefile.Close
End Function

Function SelectFolder(myStartFolder)
    SelectFolder = vbNull

    Set objFolder = objShellApp.BrowseForFolder(0, "Select Folder", 0, myStartFolder)
    If IsObject( objfolder ) Then 
        SelectFolder = objFolder.Self.Path
    End If
End Function

Function SetStartDir
    strPath = SelectFolder(objShell.CurrentDirectory)
    If strPath = vbNull Then
        WScript.Echo "Cancelled"
        WScript.Quit
    Else
        objShell.CurrentDirectory = strPath
    End If
End Function

Function SetProjectVariables
    assemblyname = name
    rootnamespace = name
End Function


''''Main
SetStartDir()
GetMakefileLocation()
FindProjectNameMakefile()
SetProjectVariables()

FindProjectFiles()

GenerateAtmelStudioCproj(name + ".cproj")

'Debug
'PrintDirList()
'PrintFileList()