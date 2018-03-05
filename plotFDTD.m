function plotFDTD(filename)

fid = fopen(filename, 'rb');

size_x = fread(fid, 1, 'int');
size_y = fread(fid, 1, 'int');
times = fread(fid, 1, 'int');
data_all = zeros(size_y, size_x, times);
x=0:1:size_x-1;
y=0:1:size_y-1;

for tt = 1 : times
    data = fread(fid, [size_y size_x], 'double');
    z_norm = 1;
    %surf(log10(abs((data + realmin)) / z_norm))
    mesh(x,y,abs((data + realmin)) / z_norm,'linewidth',2);
    xlabel('X \rightarrow');
    ylabel('\leftarrow Y');
    zlabel('E_z \rightarrow');
    titlestring=['\fontsize{20}Plot of E_z vs X & Y for 2D FDTD with PML at time step = ',num2str(tt)];
    title(titlestring,'color','k');
    axis([1 size_x 1 size_y -2 2])
    %colorbar
    getframe;
end
end