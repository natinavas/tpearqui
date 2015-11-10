include Makefile.inc
SAMPLE_DATA=0001-sampleDataModule.bin

all: sampleCodeModule sampleDataModule

sampleCodeModule:
	cd SampleCodeModule; make all

sampleDataModule:
	printf “D1K1P1S1P1K1G1K1D1K1P1S1P1K1G10” >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)

clean:
	cd SampleCodeModule; make clean
	rm -rf *.bin


.PHONY: sampleCodeModule all clean
