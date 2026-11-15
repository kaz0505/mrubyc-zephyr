# mruby/c on zephyr

## Setup

- First of all, setup zephyr development environment  
  https://docs.zephyrproject.org/latest/develop/getting_started/index.html

## Build

- Change current directory to `zephyrproject`
- Build as follows
```
west build -p auto -b <board name> <path/mrubyc-zephyr>
