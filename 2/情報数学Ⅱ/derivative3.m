[x,y] = meshgrid( -2:0.1:2, -2:0.1:2 );
z = x.*exp(-x.^2 - y.^2);

figure(1)
clf;
surface( x, y, z )
xlabel("x")
ylabel("y")

[zx,zy] = gradient(z);

figure(2)
clf;
surface( x, y, zx )
xlabel("x")
ylabel("y")

figure(3)
clf;
surface( x, y, zy )
xlabel("x")
ylabel("y")
