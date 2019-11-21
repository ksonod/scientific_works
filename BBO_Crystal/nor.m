%Refractive indices (Sellmeier's equation)
%Valid in the full transparency range (0.188-5.2 um) of BBO crystal.

%Ordinary ray

% G. Tamosauskas, G. Beresnevicius, D. Gadonas, and A. Dubietis, 
% Opt. Mater. Express, 8, 1410 (2018)

function ret=nor(lambda)  % lambda [um]
lamsq=lambda*lambda;

B1=0.90291;
B2=0.83155;
B3=0.76536;
C1=0.003926;
C2=0.01876;
C3=60.01;

ret=sqrt(1+B1*lamsq/(lamsq-C1)+B2*lamsq/(lamsq-C2)+B3*lamsq/(lamsq-C3));
end
