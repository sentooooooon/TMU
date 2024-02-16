%%%
%%% 情報数学II
%%% 最急降下法
%%%
%%% coded by Nobutaka Ono (onono@tmu.ac.jp), Dec. 2019
%%%

clear;
     
%%% 初期値、パラメータの設定
itr=30;           % 反復回数
x=zeros(1,itr);
y=zeros(1,itr);
mu = 0.3;         % ステップサイズ

x(1,1)= 1;        % 初期値
y(1,1)= 1;        % 初期値

%%% 最急降下法
for n=1:itr-1
  dx =   (1-2*x(1,n)^2)*exp(-x(1,n)^2-y(1,n)^2); % x微分の計算
  dy = -2*x(1,n)*y(1,n)*exp(-x(1,n)^2-y(1,n)^2); % y微分の計算
  x(1,n+1)=x(1,n)-mu*dx;
  y(1,n+1)=y(1,n)-mu*dy;
end

%%% 表示
[X,Y] = meshgrid(-2:0.02:2,-2:0.02:2);
Z = X.*exp(-X.^2 - Y.^2);
contour(X,Y,Z,20); % 等高線の表示
xlabel('x');
ylabel('y');
hold on;
for n=1:itr
  plot(x(1,n), y(1,n), 'p');
end
hold off;
