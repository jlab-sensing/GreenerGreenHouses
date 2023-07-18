syms x

f = piecewise(x>0 & x <= 30,15,x > 30 & x <= 50, x-15,x > 50 & x <= 80, 35 ,x > 80 & x <= 100,-x+115,x>100 & x<=130,15,x>130 & x<=160,35,x>160 & x <=190,15);
figure(1)
fplot(f)
title('Suggested Temperature Profile')
xlabel('Time [Min]')
ylabel('Degree [C]')
legend("Temperature Profile")

figure(2)
h = piecewise(x>0 & x <= 180,.25*x+50);
fplot(h)
title('Suggested Humidity Profile')
xlabel('Time [Min]')
ylabel('Humidity [%]')
legend('Humidity Profile')