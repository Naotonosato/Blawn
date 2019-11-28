#!/bin/bash

if ! git rev-parse --is-inside-work-tree > /dev/null 2>&1; then
  exit 1
fi

if [ "$(pwd)" != "$(git rev-parse --show-toplevel)" ]; then
  exit 1
fi
