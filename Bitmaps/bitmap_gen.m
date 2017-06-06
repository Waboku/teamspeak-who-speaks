%Generate Bitmaps



list = dir([pwd '\*.png' ]);

for fileCount = 1:length(list)
   
    clear imgData 

    [imgData] = imread(list(fileCount).name);

    [y, x, c] = size(imgData);

    filename = strrep(list(fileCount).name(1:end-4),' ', '_');

    fileID = fopen([filename '.h'],'w');

    fprintf(fileID,'/*\n');
    fprintf(fileID,[' * ' filename '.h\n']);
    fprintf(fileID,' *\n');
    fprintf(fileID,' *Generated by matlab\n');
    fprintf(fileID,' */ \n');
    fprintf(fileID,'\n');
    fprintf(fileID,'\n');
    fprintf(fileID,['#ifndef ' upper(filename) '_H_\n']);
    fprintf(fileID,['#define ' upper(filename) '_H_\n']);
    fprintf(fileID,'\n');
    fprintf(fileID,'\n');
    fprintf(fileID,'#include <avr/pgmspace.h>\n');
    fprintf(fileID,'\n');
    fprintf(fileID,['//Image: ' filename '   size: ' num2str(x) 'x' num2str(y) ' pixels \n']);
    fprintf(fileID, ['\nconst RGBcolor_t ' filename '_data[' num2str(y*x) '];\n']);
    fprintf(fileID,'\n');
    fprintf(fileID,['bitmap_t ' filename ' = {.xSize = ' num2str(x) ', .ySize = ' num2str(y) ', .data = ' filename '_data};']);
    fprintf(fileID,'\n');
    fprintf(fileID,'\n');
    fprintf(fileID, '/*The image data encoded in RGBcolor_t*/');
    fprintf(fileID, ['\nconst RGBcolor_t ' filename '_data[' num2str(y*x) '] = {\t\n']);


    for xc = 1:x
      for yc = 1:y
        fprintf(fileID, '\t\t\t{ .red = ');      
        fprintf(fileID, num2str(imgData(yc,xc,1),'0x%02x'));
        fprintf(fileID, ', .green = ');      
        fprintf(fileID, num2str(imgData(yc,xc,2),'0x%02x'));
        fprintf(fileID, ', .blue = ');    
        fprintf(fileID, num2str(imgData(yc,xc,3),'0x%02x'));
        fprintf(fileID, '}, \n');
      end
      fprintf(fileID,'\n');
    end

    fprintf(fileID,'};\n\n\n');
    fprintf(fileID,'\n\n\n');
    fprintf(fileID,['#endif /*' upper(filename) '_H_*/']);

    fclose(fileID);

end
