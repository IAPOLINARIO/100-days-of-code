#!/bin/sh
basedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")

case `uname` in
    *CYGWIN*) basedir=`cygpath -w "$basedir"`;;
esac

if [ -x "$basedir/node" ]; then
  "$basedir/node"  "$basedir/../tape/bin/tape" "$@"
  ret=$?
else 
  node  "$basedir/../tape/bin/tape" "$@"
  ret=$?
fi
exit $ret
