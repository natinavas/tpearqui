include Makefile.inc
SAMPLE_DATA=0001-sampleDataModule.bin

all: sampleCodeModule sampleDataModule

sampleCodeModule:
	cd SampleCodeModule; make all

sampleDataModule:
	printf “D1K1P1S1P1K1G1K1D1K1P1S1P1K1G1K1F1L1P1R1P1L1G1I1F1K1O1R1O1K1A1K1B1L1P1S1P1L1G1L1D1K1P1S1P1K1A1K1B1J1P1V1P1J1G1J1B1J1P1U4E1L1Q1U1Q1L1I1L1E1K1Q1U1T30” >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)
	printf “K1J3K1J3A2B2H1J1K1K1J1H1J1K1K1J1H1J1K1K1J1H1J1K1K1J1H1J1K1K1J1H1J1K10” >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)


clean:
	cd SampleCodeModule; make clean
	rm -rf *.bin


.PHONY: sampleCodeModule all clean
