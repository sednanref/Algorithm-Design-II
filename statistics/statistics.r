rm(list=ls()) #Remove the data.
#Load the data (and optimal values)
#nug12
ils_nug12_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug12.dat.txt")
ils_nug12 = ils_nug12_dat[,1]
ts_nug12_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug12.dat.txt")
ts_nug12 = ts_nug12_dat[,1]
nug12_opt = 578
#nug14
ils_nug14_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug14.dat.txt")
ils_nug14 = ils_nug14_dat[,1]
ts_nug14_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug14.dat.txt")
ts_nug14 = ts_nug14_dat[,1]
nug14_opt = 1014
#nug15
ils_nug15_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug15.dat.txt")
ils_nug15 = ils_nug15_dat[,1]
ts_nug15_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug15.dat.txt")
ts_nug15 = ts_nug15_dat[,1]
nug15_opt = 1150
#nug16a
ils_nug16a_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug16a.dat.txt")
ils_nug16a = ils_nug16a_dat[,1]
ts_nug16a_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug16a.dat.txt")
ts_nug16a = ts_nug16a_dat[,1]
nug16a_opt = 1610
#nug16b
ils_nug16b_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug16b.dat.txt")
ils_nug16b = ils_nug16b_dat[,1]
ts_nug16b_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug16b.dat.txt")
ts_nug16b = ts_nug16b_dat[,1]
nug16b_opt = 1240
#nug17
ils_nug17_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug17.dat.txt")
ils_nug17 = ils_nug17_dat[,1]
ts_nug17_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug17.dat.txt")
ts_nug17 = ts_nug17_dat[,1]
nug17_opt = 1732
#nug18
ils_nug18_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug18.dat.txt")
ils_nug18 = ils_nug18_dat[,1]
ts_nug18_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug18.dat.txt")
ts_nug18 = ts_nug18_dat[,1]
nug18_opt = 1930
#nug20
ils_nug20_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug20.dat.txt")
ils_nug20 = ils_nug20_dat[,1]
ts_nug20_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug20.dat.txt")
ts_nug20 = ts_nug20_dat[,1]
nug20_opt = 2570
#nug21
ils_nug21_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug21.dat.txt")
ils_nug21 = ils_nug21_dat[,1]
ts_nug21_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug21.dat.txt")
ts_nug21 = ts_nug21_dat[,1]
nug21_opt = 2438
#nug22
ils_nug22_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug22.dat.txt")
ils_nug22 = ils_nug22_dat[,1]
ts_nug22_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug22.dat.txt")
ts_nug22 = ts_nug22_dat[,1]
nug22_opt = 3596
#nug24
ils_nug24_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug24.dat.txt")
ils_nug24 = ils_nug24_dat[,1]
ts_nug24_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug24.dat.txt")
ts_nug24 = ts_nug24_dat[,1]
nug24_opt = 3488
#nug25
ils_nug25_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug25.dat.txt")
ils_nug25 = ils_nug25_dat[,1]
ts_nug25_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug25.dat.txt")
ts_nug25 = ts_nug25_dat[,1]
nug25_opt = 3744
#nug27
ils_nug27_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug27.dat.txt")
ils_nug27 = ils_nug27_dat[,1]
ts_nug27_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug27.dat.txt")
ts_nug27 = ts_nug27_dat[,1]
nug27_opt = 5234
#nug28
ils_nug28_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug28.dat.txt")
ils_nug28 = ils_nug28_dat[,1]
ts_nug28_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug28.dat.txt")
ts_nug28 = ts_nug28_dat[,1]
nug28_opt = 5166
#nug30
ils_nug30_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ils/nug30.dat.txt")
ils_nug30 = ils_nug30_dat[,1]
ts_nug30_dat = read.table("/home/lfernandes/Algorithm-Design-II/results/ts/nug30.dat.txt")
ts_nug30 = ts_nug30_dat[,1]
nug30_opt = 6124


#Errores Relativos
#nug12
print("Error relativo promedio de Nug12 con ILS: ")
print((mean(ils_nug12) - nug12_opt)/nug12_opt)
print("Error relativo promedio de Nug12 con TS: ")
print((mean(ts_nug12) - nug12_opt)/nug12_opt)
#nug14
print("Error relativo promedio de Nug14 con ILS: ")
print((mean(ils_nug14) - nug14_opt)/nug14_opt)
print("Error relativo promedio de Nug14 con TS: ")
print((mean(ts_nug14) - nug14_opt)/nug14_opt)
#nug15
print("Error relativo promedio de Nug15 con ILS: ")
print((mean(ils_nug15) - nug15_opt)/nug15_opt)
print("Error relativo promedio de Nug15 con TS: ")
print((mean(ts_nug15) - nug15_opt)/nug15_opt)
#nug16a
print("Error relativo promedio de Nug16a con ILS: ")
print((mean(ils_nug16a) - nug16a_opt)/nug16a_opt)
print("Error relativo promedio de Nug16a con TS: ")
print((mean(ts_nug16a) - nug16a_opt)/nug16a_opt)
#nug16b
print("Error relativo promedio de Nug16b con ILS: ")
print((mean(ils_nug16b) - nug16b_opt)/nug16b_opt)
print("Error relativo promedio de Nug16b con TS: ")
print((mean(ts_nug16b) - nug16b_opt)/nug16b_opt)
#nug17
print("Error relativo promedio de Nug17 con ILS: ")
print((mean(ils_nug17) - nug17_opt)/nug17_opt)
print("Error relativo promedio de Nug17 con TS: ")
print((mean(ts_nug17) - nug17_opt)/nug17_opt)
#nug18
print("Error relativo promedio de Nug18 con ILS: ")
print((mean(ils_nug18) - nug18_opt)/nug18_opt)
print("Error relativo promedio de Nug18 con TS: ")
print((mean(ts_nug18) - nug18_opt)/nug18_opt)
#nug20
print("Error relativo promedio de Nug20 con ILS: ")
print((mean(ils_nug20) - nug20_opt)/nug20_opt)
print("Error relativo promedio de Nug20 con TS: ")
print((mean(ts_nug20) - nug20_opt)/nug20_opt)
#nug21
print("Error relativo promedio de Nug21 con ILS: ")
print((mean(ils_nug21) - nug21_opt)/nug21_opt)
print("Error relativo promedio de Nug21 con TS: ")
print((mean(ts_nug21) - nug21_opt)/nug21_opt)
#nug22
print("Error relativo promedio de Nug22 con ILS: ")
print((mean(ils_nug22) - nug22_opt)/nug22_opt)
print("Error relativo promedio de Nug22 con TS: ")
print((mean(ts_nug22) - nug22_opt)/nug22_opt)
#nug24
print("Error relativo promedio de Nug24 con ILS: ")
print((mean(ils_nug24) - nug24_opt)/nug24_opt)
print("Error relativo promedio de Nug24 con TS: ")
print((mean(ts_nug24) - nug24_opt)/nug24_opt)
#nug25
print("Error relativo promedio de Nug25 con ILS: ")
print((mean(ils_nug25) - nug25_opt)/nug25_opt)
print("Error relativo promedio de Nug25 con TS: ")
print((mean(ts_nug25) - nug25_opt)/nug25_opt)
#nug27
print("Error relativo promedio de Nug27 con ILS: ")
print((mean(ils_nug27) - nug27_opt)/nug27_opt)
print("Error relativo promedio de Nug27 con TS: ")
print((mean(ts_nug27) - nug27_opt)/nug27_opt)
#nug28
print("Error relativo promedio de Nug28 con ILS: ")
print((mean(ils_nug28) - nug28_opt)/nug28_opt)
print("Error relativo promedio de Nug28 con TS: ")
print((mean(ts_nug28) - nug28_opt)/nug28_opt)
#nug30
print("Error relativo promedio de Nug30 con ILS: ")
print((mean(ils_nug30) - nug30_opt)/nug30_opt)
print("Error relativo promedio de Nug30 con TS: ")
print((mean(ts_nug30) - nug30_opt)/nug30_opt)


#BOXPLOTS
#nug12
boxplot(ils_nug12, ts_nug12, main=toupper("Nug12"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug12_opt, col="red")
#nug14
boxplot(ils_nug14, ts_nug14, main=toupper("Nug14"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug14_opt, col="red")
#nug15
boxplot(ils_nug15, ts_nug15, main=toupper("Nug15"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug15_opt, col="red")
#nug16a
boxplot(ils_nug16a, ts_nug16a, main=toupper("Nug16a"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug16a_opt, col="red")
#nug16b
boxplot(ils_nug16b, ts_nug16b, main=toupper("Nug16b"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug16b_opt, col="red")
#nug17
boxplot(ils_nug17, ts_nug17, main=toupper("Nug17"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug17_opt, col="red")
#nug18
boxplot(ils_nug18, ts_nug18, main=toupper("Nug18"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug18_opt, col="red")
#nug20
boxplot(ils_nug20, ts_nug20, main=toupper("Nug20"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug20_opt, col="red")
#nug21
boxplot(ils_nug21, ts_nug21, main=toupper("Nug21"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug21_opt, col="red")
#nug22
boxplot(ils_nug22, ts_nug22, main=toupper("Nug22"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug22_opt, col="red")
#nug24
boxplot(ils_nug24, ts_nug24, main=toupper("Nug24"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug24_opt, col="red")
#nug25
boxplot(ils_nug25, ts_nug25, main=toupper("Nug25"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug25_opt, col="red")
#nug27
boxplot(ils_nug27, ts_nug27, main=toupper("Nug27"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug27_opt, col="red")
#nug28
boxplot(ils_nug28, ts_nug28, main=toupper("Nug28"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug28_opt, col="red")
#nug30
boxplot(ils_nug30, ts_nug30, main=toupper("Nug30"), ylab="Solution Value", xlab="Metaheuristic", names=c("Iterated Local Search", "Tabu Search"))
abline(h=nug30_opt, col="green")