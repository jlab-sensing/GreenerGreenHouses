clear all
close all
clc

%array of samples, from 1 sample per minute to 60 samples per minute
samples = linspace(1, 60, 60)

%hdc2021 current calc at each sample rate
hdc2021_curr = ((60-samples)*0.05+samples*650)/60
hdc2021_pow = hdc2021_curr * 3
plot(samples, hdc2021_pow)
hold on

%htu21d current calc at each sample rate
htu21d_curr = ((60-samples)*0.02+samples*500)/60
htu21d_pow = htu21d_curr * 3
plot(samples, htu21d_pow)
hold on

%ens210 current calc at each sample rate
ens210_curr = ((60-samples)*0.04+samples*6.6)/60
ens210_pow = ens210_curr * 3
plot(samples, ens210_pow)



xlabel("Samples per minute")
ylabel("Power (uWatts)")
legend("hdc2021", "htu21d", "ens210")
