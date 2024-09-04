# Integration tool for E&M, PDEs, etc.

from sympy import integrate, symbols, cos, sin, exp, sqrt, diff, simplify, pi
from numpy import dot


# integration variables

x, y, z, t, u, v, r = symbols ('x y z t u v r')


# Parametrizations

def norm (v):                                                                               # vector norm
    return sqrt(dot(v,v))

def param (x,y,z):                                                                          # line, surface parametrization
    return [x,y,z]

def tang (v,t):                                                                             # tangent to parametrized line
    return [diff(v[0], t), diff(v[1], t), diff(v[2], t)]

def cross (v,w):                                                                             
    return [v[1]*w[2]-v[2]*w[1], v[2]*w[0]-v[0]*w[2], v[0]*w[1]-v[1]*w[0]]                  # normal vector parametrization
def normal (S,u,v): 
    return cross(tang(S, u), tang(S, v))                                                    


# Divergence and Curl

def div(F):
    return diff(F[0], x) + diff(F[1], y) + diff(F[2], z)
def curl(F):
    return [diff(F[2], y)-diff(F[1], z), diff(F[0], z)-diff(F[2], x), diff(F[1], x)-diff(F[0], y)]

# Integrals

def line_int_f (f, T, a, b):                                                            # scalar line integral
    return integrate(simplify(f*norm(T)), (t, a, b))

def lint_int_F (F, T, a, b):                                                            # vector line integral
    return integrate(simplify(dot(F, T)), (t, a, b))

def surf_int_f (f, n, u, v, a , b, c, d):                                               # scalar surface integral
    return integrate(simplify(integrate(simplify(f*norm(n)), (u, a, b))) , (v, c, d))

def surf_int_F (F, n, u, v, a , b, c, d):                                               # vector surface integral
    return integrate(simplify(integrate(simplify(dot(F, n)), (u, a, b))) , (v, c, d))


# Stokes' Theorem question example

F = [y,z,x]
c = curl(F)
S = param(cos(u)*sin(v), sin(u)*sin(v), cos(v))
N = normal(S,v,u)
result = surf_int_F(c, N, u, v, 0, pi/2, 0, pi/2)

print(result)