import numpy as np
from scipy import integrate

c_light= 299792458 # speed of light in m/s


def e_temporal(t,params): # temporal profile of the laser pulse
#t: fs
#params={
#    'e0':1, # amplitude
#    'fwhm':50, # FWHM in fs
#    'b':0.01*1e30, # rad/s^2
#    'wl0':800 # wavelength in nm
#}

    e0 = params['e0'] # amplitude
    fwhm=params['fwhm'] # FWHM in fs
    fwhm= fwhm*1e-15 # convert fs to s
    a=4*np.log(2)/fwhm/fwhm
    b = params['b'] # chirp term

    t=t*1e-15 # convert fs to s

    phase= b * t * t
    ret = e0 * np.exp(-a*t*t) * np.exp(1j*phase)

    return ret, phase


def e_spectral(wl,params):
# wl: wavelength  / nm
#params={
#    'e0':1, # amplitude
#    'fwhm':50, # FWHM in fs
#    'b':0.01*1e30, # rad/s^2
#    'wl0':800 # wavelength in nm
#}

    e0 = params['e0'] # amplitude
    fwhm=params['fwhm'] # FWHM in fs
    fwhm= fwhm*1e-15 # convert fs to s
    a=4*np.log(2)/fwhm/fwhm
    b = params['b']
    wl0 = params['wl0']

    omega = 2*np.pi*c_light/(wl*1e-9)
    omega0 = 2*np.pi*c_light/(wl0*1e-9)

    omegao = omega-omega0
    phase= b * omegao * omegao/(a*a+b*b)
    ret = e0 * np.pi/(a-1j*b)*np.exp(-0.25*omegao*omegao/(a-1j*b))

    return ret, phase


def g(t,params,tau):
    # t, tau: fs
    ret = np.abs(e_temporal(t-tau,params)[0])**2
#    ret = e_temporal(params, t-tau)[0]
    return ret


def real_integrant(t, params,omega,tau):
    wl0=params['wl0'] # wavelength / nm
    omega0 = 2*np.pi*c_light/(wl0*1e-9)
    omegao = omega - omega0

    ret = e_temporal(t,params)[0] * g(t,params,tau) * np.exp(-1j*omegao*t*1e-15)
    return np.real(ret)


def imag_integrant(t, params,omega,tau):
    wl0=params['wl0'] # wavelength / nm
    omega0 = 2*np.pi*c_light/(wl0*1e-9)
    omegao = omega - omega0

    ret = e_temporal(t,params)[0] * g(t,params,tau) * np.exp(-1j*omegao*t*1e-15)
    return np.imag(ret)


def frog(params,omega,tau):
    integ_range = np.array([-1e-12,1e-12])
    return integrate.quad(real_integrant, integ_range[0],integ_range[1], args=(params,omega,tau))[0]


def frog_signal(params):
    tmin = params['tmin'] # fs
    tmax = params['tmax'] # fs

    tau_min = params['tau_min'] # fs
    tau_max = params['tau_max'] # fs

    wl_min=params['wl_min'] # nm
    wl_max=params['wl_max'] # nm

    num_delay_steps = params['num_delay_steps']
    num_wl_steps = params['num_wl_steps']
    
    wl_list=np.linspace(wl_min,wl_max,num_wl_steps) # nm
    omega_list=2*np.pi*c_light/(wl_list*1e-9) # rad/s
    delay_list=np.linspace(tau_min,tau_max,num_delay_steps) # fs

    signal=[]

    for j in range(num_delay_steps):
        tau = delay_list[j]

        for k in range(num_wl_steps):
            omega=omega_list[k]

            S_real=integrate.quad(real_integrant, tmin,tmax, args=(params,omega,tau))[0]
            S_imag=integrate.quad(imag_integrant, tmin,tmax, args=(params,omega,tau))[0]

            signal.append(np.abs(S_real+1j*S_imag)**2)

    return signal, delay_list, wl_list
