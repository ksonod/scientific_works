# BBO_Crystal
These Matlab codes allow you to calculate the following optical properties of a beta-barium borate (BBO) crystal: 
* the phase-matching angle for the sum-frequency generation (SFG) process (type I)
* the dependence of the refractive indices on the wavelength.     
   
The refractive indices are calculated using the Sellmeier's equation in the functions "nex" and "nor." Some parameters that are needed for the calculation are taken from the literature (G. Tamosauskas, G. Beresnevicius, D. Gadonas, and A. Dubietis, Opt. Mater. Express, 8, 1410 (2018)).
# The calculation of the phase-matching angle
The phase-matching angle can be calculated by running "PMangle.m." You will be requested to specify the wavelengths of the two input beams (Wavelength_1 and Wavelength_2 in the unit of nm). If you choose the same wavelength for both of the input beams, the nonlinear optical process is classified as the second harmonic generation (SHG).  
As a type of the phase matching in the BBO crystal, type I is adopted. This means that the polarization directions of the input beams are the same and that the generated light has an orthogonal polarization. For example, if the imput beams are classified as e (or o) rays, the output beam is an o (or e) ray. 
The phase-matching angle is calculated using this equation:  
  
<img src="https://latex.codecogs.com/gif.latex?\theta_m&space;=\mathrm{arcsin}\left[\sqrt{\frac{\left[\lambda&space;_3\left&space;(\frac{n_o_r(\lambda_1)}{\lambda_1}&plus;\frac{n_o_r(\lambda_2)}{\lambda_2}\right)\right]^{-2}-[n_o_r(\lambda_3)]^{-2}}{[n_e_x(\lambda_3)]^{-2}-[n_o_r(\lambda_3)]^{-2}}}\right&space;]"/>  　　

Here, &lambda;<sub>1</sub> and &lambda;<sub>2</sub> are the wavelengths of the input beams and required to specify in the program. On the other hand, the output wavelength &lambda;<sub>3</sub> is calculated automatically. 

# The dependence of the refractive indices on the wavelength
The refractive indices for the extraordinary and ordinary rays can be plotted as a function of the wavelength by running the code "plotrefractiveindex.m." The calculation is conducted in the wavelength range of 0.188 - 5.2 um. It should be noted that the absorption process occurs when the wavelength exceeds 3.3 um. The transmittance is strongly affected by the thickness of the BBO crystal. For detailed discussion about the absorption, please refer to the literature (G. Tamosauskas, G. Beresnevicius, D. Gadonas, and A. Dubietis, Opt. Mater. Express, 8, 1410 (2018)).
