#!/bin/bash

sed '/\w-$/ {N; s/-\n//; N}' sed_merge_text.txt