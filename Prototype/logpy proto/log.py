from logpy import *
from logpy.arith import add,gt,sub,mul,div

x=var()
y=var()
z=var()
expr2=(add,x,y)
expr3=(add,z,3)

asdf=run(1,z,eq(x,3),eq(y,6),eq(z,expr2))
print(asdf)