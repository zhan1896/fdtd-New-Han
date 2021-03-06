clear
clc
close all

Datafilename = 'output.bin';
if (exist(Datafilename))
    delete(Datafilename);
end

parameter.timelength=200;%int
parameters.dimensionX = 60;%int  
parameters.dimensionY = 60;%int
parameters.dimensionZ = 60;%int
parameters.sourceLocationX = 20;%int  
parameters.sourceLocationY = 20;%int  
parameters.PECScattFlag = 1;%int 0: without PEC scatter; 1: with PEC scatter
parameters.PECScattLocationX = 10;%int 
parameters.PECScattLocationY = 10;%int 
parameters.PECScattDimensionX = 2;%int 
parameters.PECScattDimensionY = 2;%int

parameters.Wavelength=2.2;%double
parameters.timelength=200;%int
parameters.PMLthickness=10;%int
parameters.dx=0.2; %double
parameters.dt=0.2; %double
parameters.k_x_max=2.2; %double
parameters.k_y_max=2.2; %double
parameters.a_x_max=2.2; %double
parameters.a_y_max=2.2; %double
parameters.m_a=2.2; %double
parameters.m_chi=2.2; %double

parameters

[status, cmdout] = execuateFDTD(parameters);

plotFDTD(Datafilename);





