[x,y] = meshgrid( -2:0.1:2, -2:0.1:2 );
z = x.*exp(-x.^2 - y.^2);

figure(1)
clf;
surface( x, y, z )
xlabel("x")
ylabel("y")

dx = 0.001;
dy = 0.001;

zx = ((x+dx).*exp(-(x+dx).^2 - y.^2) - x.*exp(-x.^2 - y.^2) ) /dx;
zy = (x.*exp(-x.^2 - (y+dy).^2) - x.*exp(-x.^2 - y.^2) ) /dy;

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
