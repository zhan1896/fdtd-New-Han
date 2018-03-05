clear
clc
close all

filename = 'xcode-build/Debug/output.bin';
fid = fopen(filename, 'rb');

size_x = fread(fid, 1, 'int');
size_y = fread(fid, 1, 'int');
times = fread(fid, 1, 'int');
data_all = zeros(size_y, size_x, times);

for tt = 1 : times
    data = fread(fid, [size_y size_x], 'double');
    data_all(:, :, tt + 1) = data;
end
%%
% tt = 7;
% data = data_all(:, :, tt + 1);
% ezx = data(40, :);
% ezy = data(:, 40);
% plot(ezx), hold on
% plot(ezy, '*')

%%
% tt = 4;
% data = data_all(:, :, tt + 1);
% surf(data)
%%
tt = 5
data = data_all(:, :, tt + 1);
z_norm = 1;
surf(log10(abs((data + realmin)) / z_norm))
% surf(data)
colormap jet
% axis equal
axis([1 size_x 1 size_y])
caxis([-3 0])
colorbar