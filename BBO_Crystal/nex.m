%Refractive indices (Sellmeier's equation)
%Valid in the full transparency range (0.188-5.2 um) of BBO crystal.

%Extraordinary ray

% G. Tamosauskas, G. Beresnevicius, D. Gadonas, and A. Dubietis, 
% Opt. Mater. Express, 8, 1410 (2018)

function ret=nex(lambda)
lamsq=lambda*lambda;

B1=1.1510;
B2=0.21803;
B3=0.656;
C1=0.007142;
C2=0.02259;
C3=263;

ret=sqrt(1+B1*lamsq/(lamsq-C1)+B2*lamsq/(lamsq-C2)+B3*lamsq/(lamsq-C3));
end
