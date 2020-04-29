all:
	gcc qsort.c FIFO.c scheduling.c -o FIFO
	gcc qsort.c SJF.c scheduling.c -o SJF
	gcc qsort.c PSJF.c scheduling.c -o PSJF
	gcc qsort.c RR.c scheduling.c -o RR
	gcc main.c -o main

demo:
	sudo ./main < OS_PJ1_Test/TIME_MEASUREMENT.txt
	dmesg | grep Project
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/FIFO_1.txt  
	dmesg | grep Project 
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/PSJF_2.txt  
	dmesg | grep Project 
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/RR_3.txt 
	dmesg | grep Project 
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/SJF_4.txt  
	dmesg | grep Project 	
	sudo dmesg -C
run:
	sudo ./main < OS_PJ1_Test/TIME_MEASUREMENT.txt > output/TIME_MEASUREMENT_stdout.txt 
	dmesg | grep Project > output/TIME_MEASUREMENT_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/FIFO_1.txt > output/FIFO_1_stdout.txt 
	dmesg | grep Project > output/FIFO_1_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/FIFO_2.txt > output/FIFO_2_stdout.txt 
	dmesg | grep Project > output/FIFO_2_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/FIFO_3.txt > output/FIFO_3_stdout.txt 
	dmesg | grep Project > output/FIFO_3_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/FIFO_4.txt > output/FIFO_4_stdout.txt 
	dmesg | grep Project > output/FIFO_4_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/FIFO_5.txt > output/FIFO_5_stdout.txt 
	dmesg | grep Project > output/FIFO_5_dmesg.txt
	sudo dmesg -C

	sudo ./main < OS_PJ1_Test/RR_1.txt > output/RR_1_stdout.txt 
	dmesg | grep Project > output/RR_1_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/RR_2.txt > output/RR_2_stdout.txt 
	dmesg | grep Project > output/RR_2_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/RR_3.txt > output/RR_3_stdout.txt 
	dmesg | grep Project > output/RR_3_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/RR_4.txt > output/RR_4_stdout.txt 
	dmesg | grep Project > output/RR_4_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/RR_5.txt > output/RR_5_stdout.txt 
	dmesg | grep Project > output/RR_5_dmesg.txt
	sudo dmesg -C

	sudo ./main < OS_PJ1_Test/SJF_1.txt > output/SJF_1_stdout.txt 
	dmesg | grep Project > output/SJF_1_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/SJF_2.txt > output/SJF_2_stdout.txt 
	dmesg | grep Project > output/SJF_2_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/SJF_3.txt > output/SJF_3_stdout.txt 
	dmesg | grep Project > output/SJF_3_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/SJF_4.txt > output/SJF_4_stdout.txt 
	dmesg | grep Project > output/SJF_4_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/SJF_5.txt > output/SJF_5_stdout.txt 
	dmesg | grep Project > output/SJF_5_dmesg.txt
	sudo dmesg -C

	sudo ./main < OS_PJ1_Test/PSJF_1.txt > output/PSJF_1_stdout.txt 
	dmesg | grep Project > output/PSJF_1_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/PSJF_2.txt > output/PSJF_2_stdout.txt 
	dmesg | grep Project > output/PSJF_2_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/PSJF_3.txt > output/PSJF_3_stdout.txt 
	dmesg | grep Project > output/PSJF_3_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/PSJF_4.txt > output/PSJF_4_stdout.txt 
	dmesg | grep Project > output/PSJF_4_dmesg.txt
	sudo dmesg -C
	sudo ./main < OS_PJ1_Test/PSJF_5.txt > output/PSJF_5_stdout.txt 
	dmesg | grep Project > output/PSJF_5_dmesg.txt
	sudo dmesg -C
