#! /usr/bin/env bash

set -o errexit

function main
{
  if ! ./func ; then
    echo "ERROR: func failed"
    exit 1
  fi
  echo "Success"
}

main $@
