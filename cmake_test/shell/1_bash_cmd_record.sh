#!/bin/bash

sudo find . -type f -size +100M | xargs ls -lh


sudo dcos_debug cmdlist | sed -e'/maid/d'| wc -l
