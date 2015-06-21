rm(list=ls()) #Remove the data.
#Load the data (and optimal values)
#nug12
ils_nug12_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug12.hola")
ils_nug12 = ils_nug12_dat[,1]
ts_nug12_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug12.hola")
ts_nug12 = ts_nug12_dat[,1]
ga_nug12_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug12.hola")
ga_nug12 = ga_nug12_dat[,1]
ss_nug12_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug12.hola")
ss_nug12 = ss_nug12_dat[,1]
#nug14
ils_nug14_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug14.hola")
ils_nug14 = ils_nug14_dat[,1]
ts_nug14_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug14.hola")
ts_nug14 = ts_nug14_dat[,1]
ga_nug14_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug14.hola")
ga_nug14 = ga_nug14_dat[,1]
ss_nug14_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug14.hola")
ss_nug14 = ss_nug14_dat[,1]
#nug15
ils_nug15_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug15.hola")
ils_nug15 = ils_nug15_dat[,1]
ts_nug15_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug15.hola")
ts_nug15 = ts_nug15_dat[,1]
ga_nug15_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug15.hola")
ga_nug15 = ga_nug15_dat[,1]
ss_nug15_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug15.hola")
ss_nug15 = ss_nug15_dat[,1]
#nug16a
ils_nug16a_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug16a.hola")
ils_nug16a = ils_nug16a_dat[,1]
ts_nug16a_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug16a.hola")
ts_nug16a = ts_nug16a_dat[,1]
ga_nug16a_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug16a.hola")
ga_nug16a = ga_nug16a_dat[,1]
ss_nug16a_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug16a.hola")
ss_nug16a = ss_nug16a_dat[,1]
#nug16b
ils_nug16b_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug16b.hola")
ils_nug16b = ils_nug16b_dat[,1]
ts_nug16b_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug16b.hola")
ts_nug16b = ts_nug16b_dat[,1]
ga_nug16b_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug16b.hola")
ga_nug16b = ga_nug16b_dat[,1]
ss_nug16b_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug16b.hola")
ss_nug16b = ss_nug16b_dat[,1]
#nug17
ils_nug17_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug17.hola")
ils_nug17 = ils_nug17_dat[,1]
ts_nug17_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug17.hola")
ts_nug17 = ts_nug17_dat[,1]
ga_nug17_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug17.hola")
ga_nug17 = ga_nug17_dat[,1]
ss_nug17_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug17.hola")
ss_nug17 = ss_nug17_dat[,1]
#nug18
ils_nug18_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug18.hola")
ils_nug18 = ils_nug18_dat[,1]
ts_nug18_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug18.hola")
ts_nug18 = ts_nug18_dat[,1]
ga_nug18_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug18.hola")
ga_nug18 = ga_nug18_dat[,1]
ss_nug18_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug18.hola")
ss_nug18 = ss_nug18_dat[,1]
#nug20
ils_nug20_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug20.hola")
ils_nug20 = ils_nug20_dat[,1]
ts_nug20_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug20.hola")
ts_nug20 = ts_nug20_dat[,1]
ga_nug20_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug20.hola")
ga_nug20 = ga_nug20_dat[,1]
ss_nug20_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug20.hola")
ss_nug20 = ss_nug20_dat[,1]
#nug21
ils_nug21_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug21.hola")
ils_nug21 = ils_nug21_dat[,1]
ts_nug21_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug21.hola")
ts_nug21 = ts_nug21_dat[,1]
ga_nug21_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug21.hola")
ga_nug21 = ga_nug21_dat[,1]
ss_nug21_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug21.hola")
ss_nug21 = ss_nug21_dat[,1]
#nug22
ils_nug22_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug22.hola")
ils_nug22 = ils_nug22_dat[,1]
ts_nug22_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug22.hola")
ts_nug22 = ts_nug22_dat[,1]
ga_nug22_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug22.hola")
ga_nug22 = ga_nug22_dat[,1]
ss_nug22_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug22.hola")
ss_nug22 = ss_nug22_dat[,1]
#nug24
ils_nug24_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug24.hola")
ils_nug24 = ils_nug24_dat[,1]
ts_nug24_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug24.hola")
ts_nug24 = ts_nug24_dat[,1]
ga_nug24_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug24.hola")
ga_nug24 = ga_nug24_dat[,1]
ss_nug24_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug24.hola")
ss_nug24 = ss_nug24_dat[,1]
#nug25
ils_nug25_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug25.hola")
ils_nug25 = ils_nug25_dat[,1]
ts_nug25_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug25.hola")
ts_nug25 = ts_nug25_dat[,1]
ga_nug25_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug25.hola")
ga_nug25 = ga_nug25_dat[,1]
ss_nug25_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug25.hola")
ss_nug25 = ss_nug25_dat[,1]
#nug27
ils_nug27_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug27.hola")
ils_nug27 = ils_nug27_dat[,1]
ts_nug27_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug27.hola")
ts_nug27 = ts_nug27_dat[,1]
ga_nug27_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug27.hola")
ga_nug27 = ga_nug27_dat[,1]
ss_nug27_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug27.hola")
ss_nug27 = ss_nug27_dat[,1]
#nug28
ils_nug28_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug28.hola")
ils_nug28 = ils_nug28_dat[,1]
ts_nug28_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug28.hola")
ts_nug28 = ts_nug28_dat[,1]
ga_nug28_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug28.hola")
ga_nug28 = ga_nug28_dat[,1]
ss_nug28_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug28.hola")
ss_nug28 = ss_nug28_dat[,1]
#nug30
ils_nug30_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug30.hola")
ils_nug30 = ils_nug30_dat[,1]
ts_nug30_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug30.hola")
ts_nug30 = ts_nug30_dat[,1]
ga_nug30_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ga/nug30.hola")
ga_nug30 = ga_nug30_dat[,1]
ss_nug30_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ss/nug30.hola")
ss_nug30 = ss_nug30_dat[,1]
