close all
clc
clear

filename = 'xcode-build/Debug/debug.bin';
fid = fopen(filename, 'rb');

bx_len = fread(fid, 1, 'int');
bx = fread(fid, bx_len, 'double');

by_len = fread(fid, 1, 'int');
by = fread(fid, by_len, 'double');

cx_len = fread(fid, 1, 'int');
cx = fread(fid, cx_len, 'double');

cy_len = fread(fid, 1, 'int');
cy = fread(fid, cy_len, 'double');

subplot(1, 2, 1)
plot(cx)
title('cx')
subplot(1, 2, 2)
plot(bx)
title('bx')
% for i = 0 : 4
%     lenx = fread(fid, 1, 'int');
%     leny = fread(fid, 1, 'int');
%     Psi_pos = fread(fid, [leny lenx], 'double');
% end
% 
% surf(Psi_pos)
% xlabel('x')
% ylabel('y')
% plot(ezx), hold on, plot(ezy)