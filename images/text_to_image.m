file = fopen('write1.txt', 'r');

for i = 1:640
    for j = 1:480
       image = fscanf(file, '%d');
    end
end


fclose(file);

outImg = imshow(image);
