# Wave Server

This is a toy project exploring how to make small,
single-purpose applications in line with the suckless 
and unix philosophy.

The purpose of the server is to serve wave states
for marine simulations such that multiple simulators
can share a common environmental state.

The idea is to implement long crested and short crested 
waves as spearate applications. Each application should only
generate the static part of the wave state to files or standard
out.

Hence, the wave state can be served as static files over http or other
protocols such as mqtt. An important part of this expirement is to avoid
implementing networking in the applications generating data.

The end goal is a set of several small applications that are glued together
by shell scripts.



