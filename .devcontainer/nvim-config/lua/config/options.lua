-- Options are automatically loaded before lazy.nvim startup
-- Default options that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/options.lua
-- Add any additional options here

vim.g.autoformat = false -- Disable auto-formatting on save

local opt = vim.opt

-- General indentation settings
opt.tabstop = 4 -- A TAB character looks like 4 spaces
opt.softtabstop = 4 -- Number of spaces inserted instead of a TAB character
opt.shiftwidth = 4 -- Size of an indent
opt.expandtab = true -- Pressing the TAB key will insert spaces instead of a TAB character
