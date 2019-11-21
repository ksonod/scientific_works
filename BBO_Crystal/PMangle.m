% Calculation of the phase matching (PM) angle
% for SFG using the BBO (beta-barium borate) crystal (type-I).

disp('THE CALCULATION OF THE PHASE-MATCHING ANGLE');
disp('Crystal: Beta-barium borate (BBO)');
disp('Type of the phase-matching: type I');

inp = 'Wavelength_1 [nm]:';
lambda1 = input(inp)/1000; % converted into um
inp = 'Wavelength_2 [nm]:';
lambda2 = input(inp)/1000; % converted into um

lambda3=1/(1/lambda1+1/lambda2); % um

% G. Tamosauskas, G. Beresnevicius, D. Gadonas, and A. Dubietis, 
% Opt. Mater. Express, 8, 1410 (2018)
lambda_min=0.188; % um
lambda_max=5.2; % um

if lambda3<lambda_min
    disp('The wavelength of SFG is too short.');
elseif lambda_max<lambda1 || lambda_max<lambda2
    disp('The wavelength of the input beam is too long.')
else
   PMtheta=180/pi*asin(sqrt((((lambda3)*(nor(lambda1)/lambda1...
        +nor(lambda2)/lambda2))^-2-nor(lambda3)^-2)...
        /(nex(lambda3)^-2-nor(lambda3)^-2)));

    %Showing results
    disp('%%%%% Results %%%%%');
    OutputWavelength=sprintf('%.1f nm',lambda3*1000)
    PhaseMatchingAngle=sprintf('%.1f deg.',PMtheta)
end

clear inp lambda1 lambda2 lambda3 lambda_max lambda_min PMtheta...
    OutputWavelength PhaseMatchingAngle;