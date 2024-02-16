% x^3 の導関数
x = [-2:0.01:2];
y = x.^3;

dx = 0.0001;
dy = ((x+dx).^3-x.^3)/dx;

figure(1)
clf;                    % figure を真っ白にするための初期化関数
hold on;                % １つのグラフに２つ以上をプロットするために用いる hold off されるまで有効
    plot( x, y )
    plot( x, dy )
    legend( "y", "dy")
hold off;


% sinの導関数
y2 = sin(x);
dy2 = (sin(x+dx)-sin(x))/dx;

figure(2)
clf;                    
hold on;                
    plot( x, y2 )
    plot( x, dy2 )
    legend( "sin", "cos")
hold off;
