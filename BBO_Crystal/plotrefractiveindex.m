%Refractive indices (Sellmeier's equation)
%Valid in the transparency range (0.188-5.2 um) of BBO crystals (type-I).
% G. Tamosauskas, G. Beresnevicius, D. Gadonas, and A. Dubietis, 
% Opt. Mater. Express, 8, 1410 (2018)
lambda_min=0.188; % um
lambda_max=5.2; % um

num=(lambda_max-lambda_min)*1000+1;
lambda=zeros(num,1);
n_e=zeros(num,1);
n_o=zeros(num,1);


for j=1:1:num
    lambda(j,1)=lambda_min+(j-1)*0.001;
    n_e(j,1)=nex(lambda(j,1));
    n_o(j,1)=nor(lambda(j,1));
end

plot(lambda,n_e,lambda,n_o);
xlabel('Wavelength [\mum]');
ylabel('Reflective indices');
legend('n_e','n_o');

clear j lambda_max lambda_min num;