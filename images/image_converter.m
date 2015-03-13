image = imread('image2.jpeg');    % take this image
gray = rgb2gray(image);         % grayscale it
image = imresize(image, [480 640]); % resize it 480 x 640

file = fopen('image2.txt', 'wt');    % make a text file
for i = 1:640
    for j = 1:480
        fprintf(file, '%d ', image(j,i));
    end
end
fclose(file);