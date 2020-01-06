# scientific_works
The codes published here are written for conducting scientific numerical simulations and data analysis. Numerical simulations based on various models help us to interpret experimental results, allow us to predict interesting phenomena that have never been experimentally observed, and give us hints for optimizing experimental conditions. Data analysis tools improve the efficiency of work, allow us to extract high-quality information, transform messy raw data into exciting insights, and produce sophisticated graphs for conveying our findings to other people in an effective way.  
 
Other types of analysis that are not listed here are also published on my GitHub (e.g., [statistical analysis](https://github.com/ksonod/my_statistics))

## Table of Contents
<strong>Tools for numerical simulation and scientific calculation</strong>
- [convnet_for_pg-frog](https://github.com/ksonod/scientific_works#convnet_for_pg-frog)
- [RKR_potential_CO_Xstate](https://github.com/ksonod/scientific_works#rkr_potential_co_xstate)  
- [H_ADK](https://github.com/ksonod/scientific_works#h_adk)   
- [SHG_autocorrelation](https://github.com/ksonod/scientific_works#shg_autocorrelation)
- [BBO_Crystal](https://github.com/ksonod/scientific_works#bbo_crystal)
  
<strong>Data analysis tools</strong>
- [calibration_and_spectroscopic_resolution](https://github.com/ksonod/scientific_works#calibration_and_spectroscopic_resolution)
- [derivative_spectra](https://github.com/ksonod/scientific_works#derivative_spectra)
- [cleaning_image](https://github.com/ksonod/scientific_works#cleaning_image)

# Numerical simulation and scientific calculation
## [convnet_for_pg-frog](https://github.com/ksonod/scientific_works/tree/master/convnet_for_pg-frog)
<img src="https://i.imgur.com/f7z6arM.png" width="700px">     
 
1. <strong>Description</strong>: The temporal profile of femtosecond laser pulses, i.e., pulse width and temporal chirp parameters, is retrieved by analyzing traces of polarization-gated [frequency-resolved optical gating](https://en.wikipedia.org/wiki/Frequency-resolved_optical_gating) (PG-FROG) using a convolutional neural network. The model can quickly characterize laser pulses once training process is finished.    
2. <strong>Programming language</strong>: Python (Python 3, keras, Jupyter Notebook, Google Colab)   
3. <strong>Technical keywords</strong>: regression, numerical integration, image processing, Fourier transform, convolutional neural network, cross validation, standardization, GPU   
4. <strong>Scientific keywords</strong>: PG-FROG, ultrashort laser pulse, convolutional neural network    


## [RKR_potential_CO_Xstate](https://github.com/ksonod/scientific_works/tree/master/RKR_potential_CO_Xstate)
<img src="https://i.imgur.com/uYPP5vJ.png" width="500px">    

1. <strong>Description</strong>: The potential energy curve of CO in the X state is calculated using Rydberg-Klein-Rees method. In order to avoid singular points in integrals, Watson's method is used. The integrals are numerically calculated using Simpson's method. The calculated potential energy curve can be used for various applications, e.g., evaluation of optical transition probability based on Franck-Condon factors.  
2. <strong>Programming language</strong>: C
3. <strong>Technical keywords</strong>: numerical integration, avoiding singular points in integral, creating text files
4. <strong>Scientific keywords</strong>: RKR potential, Watson's method

## [H_ADK](https://github.com/ksonod/scientific_works/tree/master/H_ADK)
<img src="https://i.imgur.com/Kxu3jsE.png" width="500px">   

1. <strong>Description</strong>: [Tunneling ionization](https://en.wikipedia.org/wiki/Tunnel_ionization) rate of H atom is calculated using Ammosov-Delone-Krainov theory. The ionization probability is also obtained by integrating a rate equation. By visualizing the ionization rate and probability as a function of time, it is possible to reveal how fast the tunneling ionization occurs in the unperturbative laser field.
2. <strong>Programming language</strong>: C/C++
3. <strong>Technical keywords</strong>: Numerical integration, creating text files
4. <strong>Scientific keywords</strong>: Tunneling ionization, intense laser field, Ammosov-Delone-Krainov theory, rate equation

## N2_alignment
1. <strong>Description</strong>: Coherent rotational dynamics of N2 molecules induced by non-resonant intense femtosecond laser pulses is numerically calculated. Time dependent Schrödinger equation is numerically solved using 4-th order Runge-Kutta method. 
2. <strong>Programming language</strong>: C/C++
3. <strong>Technical keywords</strong>: 4-th order Runge-Kutta method for solving simultaneous differential equations, creating text files
4. <strong>Scientific keywords</strong>: molecular alignment, rotational Raman excitation, coherent rotational dynamics, rotational-state distribution, Time dependent Schrödinger equation

## [SHG_autocorrelation](https://github.com/ksonod/scientific_works/tree/master/SHG_autocorrelation)
<img src="https://i.imgur.com/xYauuc1.png" width="500px">  
  
1. <strong>Description</strong>: The [autocorrelation](https://en.wikipedia.org/wiki/Optical_autocorrelation) trace of ultrashort pulses are simulated. By comparing the simulated results with a measured autocorrelation signal, the pulse width of femtosecond pulses can be determined. 
2. <strong>Programing Language</strong>: C/C++
3. <strong>Technical keywords</strong>: [autocorrelation](https://en.wikipedia.org/wiki/Optical_autocorrelation), numerical integration
4. <strong>Scientific keywords</strong>: ultrashort pulse measurement, SHG [autocorrelation](https://en.wikipedia.org/wiki/Optical_autocorrelation)

## [BBO_Crystal](https://github.com/ksonod/scientific_works/tree/master/BBO_Crystal)
<img src="https://i.imgur.com/z3uWpco.jpg" width="500px">

1. <strong>Description</strong>: The phase-matching angle for the sum-frequency generation (SFG) or second harmonic generation (SHG) is calculated for a beta-barium borate ([BBO](https://en.wikipedia.org/wiki/Barium_borate)) crystal (type I). The dependence of the [refractive indices](https://en.wikipedia.org/wiki/Refractive_index) on the wavelength is also obtained. These calculations are needed when designing optical setups.  
2. <strong>Programming language</strong>: Matlab
3. <strong>Technical keywords</strong>: interactive command line
4. <strong>Scientific keywords</strong>: [BBO](https://en.wikipedia.org/wiki/Barium_borate) crystal, phase-matching angle, [refractive indices](https://en.wikipedia.org/wiki/Refractive_index), [Sellmeier's equation](https://en.wikipedia.org/wiki/Sellmeier_equation)


# Data analysis
## [calibration_and_spectroscopic_resolution](https://github.com/ksonod/scientific_works/tree/master/calibration_and_spectroscopic_resolution)
<img src="https://i.imgur.com/w3niDIb.png" width="500px">    

1. <strong>Description</strong>: The soft X-ray energy in an absorption spectrum of sulfur hexafluoride (SF<sub>6</sub>) is calibrated using regression analysis. The observed peaks are fitted with Voigt function whose full-width at half maximum (FWHM) of the Lorentzian component is taken from literature and fixed. With this fitting method, the energy resolution of a spectrometer is evaluated using the determined Gaussian component of the Voigt function. Even though the soft X-ray absorption spectrum is used for the present data analysis, this analytical method can be applied to various spectroscopic data in different photon energy.
2. <strong>Programing Language</strong>: Python (Jupyter Notebook)
3. <strong>Technical keywords</strong>: regression analysis, fitting data with Voigt function, data visualization based on Matplotlib and Plotly
4. <strong>Scientific keywords</strong>: soft-X ray absorption spectroscopy, energy calibration, peak analysis, spectral resolution

## [derivative_spectra](https://github.com/ksonod/scientific_works/blob/master/derivative_spectra/derivative_spectra.ipynb)
<img src="https://i.imgur.com/83zIhKW.png" width="500px">    

1. <strong>Description</strong>: The first-, second-, third-, and fourth-order derivatives of spectra are obtained using Savitzky-Golay filter. If the high-order derivatives of spectra are calculated, noise is strongly enhanced. This problem is avoided by smoothing data before getting derivatives. It is also shown that the derivative spectroscopy can give us information about the peak positions and discreminate peaks that are buried in a broad band or scattering.  
2. <strong>Programing Language</strong>: Python (Jupyter Notebook)  
3. <strong>Technical keywords</strong>: Savitzky-Golay filter, derivatives, smoothing, scipy
4. <strong>Scientific keywords</strong>: derivative spectra, peak analysis, spectral discrimination, spectral resolution enhancement

## [cleaning_image](https://github.com/ksonod/scientific_works/tree/master/cleaning_image)
<img src="https://i.imgur.com/76l49IW.png" width="500px">     

1. <strong>Description</strong>: Background signal in the image of soft X-ray detected by a microchannel plate (MCP) is removed to get a clean spectrum with high contrast. 
2. <strong>Programming language</strong>: Python (Jupyter Notebook)
3. <strong>Technical keywords</strong>: image analysis, matplotlib.
4. <strong>Scientific keywords</strong>: soft X-ray, spectroscopy
