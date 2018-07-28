#!/bin/bash

SRC=$1

rsync -av --delete $SRC/math/include/math/ include/math/
rsync -av --delete $SRC/math/interface/ interface/math/
rsync -av --delete $SRC/math/src/ src/

