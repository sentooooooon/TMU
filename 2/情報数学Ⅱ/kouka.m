clear; % 変数のクリア
x=1; y=1;
(x - 2*y) * exp(-(x.^2 + y.^2));
% 関数の値を計算
for i = 1 : 10000
    dx=(1 - 2*x.^2 + 4*x*y) * exp(-(x.^2 + y.^2)); % x微分の計算
    dy=(-2 + 4*y.^2 -2*x*y) * exp(-(x.^2 + y.^2)); % y微分の計算
    mu=0.1; % ステップサイズ
    x=x-mu*dx % 勾配に沿って点を移動
    y=y-mu*dy % 勾配に沿って点を移
end
sin(x)*cos(y)