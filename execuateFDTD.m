function [status, cmdout] = execuateFDTD(parameters)

configFilename = 'configfile.cfg';
FDTDfilename ='./fdtd';

% open the config file for writing
fid = fopen(configFilename, 'w');

% write config file

% write additional statements to it.  If any sections are
% redefined, it will use the second statement
fprintf(fid, 'parameters = {  \n');
fprintf(fid, '    timelength   = "%d"   \n', round(parameters.timelength));
fprintf(fid, '    dimensionX   = "%d"   \n', round(parameters.dimensionX));
fprintf(fid, '    dimensionY   = "%d"   \n', round(parameters.dimensionY));
fprintf(fid, '    dimensionZ   = "%d"   \n', round(parameters.dimensionZ));
fprintf(fid, '    sourceLocationX   = "%d"   \n', round(parameters.sourceLocationX));
fprintf(fid, '    sourceLocationY   = "%d"   \n', round(parameters.sourceLocationY));
fprintf(fid, '    PECScattFlag   = "%d"   \n', round(parameters.PECScattFlag));
fprintf(fid, '    PECScattLocationX   = "%d"   \n', round(parameters.PECScattLocationX));
fprintf(fid, '    PECScattLocationY   = "%d"   \n', round(parameters.PECScattLocationY));
fprintf(fid, '    PECScattDimensionX   = "%d"   \n', round(parameters.PECScattDimensionX));
fprintf(fid, '    PECScattDimensionY   = "%d"   \n', round(parameters.PECScattDimensionY));
fprintf(fid, '    Wavelength   = "%f"   \n',    parameters.Wavelength);
fprintf(fid, '    PMLthickness   = "%d"   \n', round(parameters.PMLthickness));
fprintf(fid, '    dx   = "%f"   \n', parameters.dx);
fprintf(fid, '    dt   = "%f"   \n', parameters.dt);
fprintf(fid, '    k_x_max   = "%f"   \n', parameters.k_x_max);
fprintf(fid, '    k_y_max   = "%f"   \n', parameters.k_y_max);
fprintf(fid, '    a_x_max   = "%f"   \n', parameters.a_x_max);
fprintf(fid, '    a_y_max   = "%f"   \n', parameters.a_y_max);
fprintf(fid, '    m_a   = "%f"   \n', parameters.m_a);
fprintf(fid, '    m_chi   = "%f"   \n', parameters.m_chi);
fprintf(fid, '}                                 \n');
fclose(fid);

command = [ FDTDfilename ' ' configFilename ];
[status,cmdout]=system(command,'-echo'); 
