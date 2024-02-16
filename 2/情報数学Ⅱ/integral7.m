d = 0.01;
[x,y] = meshgrid( [0:d:1], [0:d:1] );

tic
z = (1-x.^2-y.^2);

zz = z > 0;

z = z .* zz;
sum(sum( z.^.5 )) * d^2 * 8

toc

%figure(1)
%clf;
%surface( x, y, z )

disp( "solution = " + 4/3 * pi )
