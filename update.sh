#!/bin/bash

make;
ssh ivan@192.168.1.102 "cd ~/WheelFactoringMPI; git pull; make";
ssh ivan@192.168.1.103 "cd ~/WheelFactoringMPI; git pull; make";
