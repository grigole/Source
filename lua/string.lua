#!/usr/bin/env lua
local a = "one string"
local b = string.gsub(a, "one", "another")  -- change string parts
print(a)       --> one string
print(b)       --> another string
