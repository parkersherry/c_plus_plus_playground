# DC-to-Frequency Ratio 
# assumes use of anthracene (C14H10) as macroscopic particles
from math import pi

V = 1500
m = 1.9E-11
Q = 1.5E-14
r = 0.035

# Find optimal ang frequency w
def q(w):
   return (8*Q*V)/(m*r**2*w**2)

# Find AC frequency f in Hertz
# def freq(w):
#     return w/(2*pi)

# # Find optimal DC amplitude U
# def a(U, w):
#    return -(4*q*U)/(m*r**2*w**2) 

h = q(2*pi*50)
print(h)