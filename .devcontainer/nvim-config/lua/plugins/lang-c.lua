-- This file configures C/C++ language support using LazyVim's conventions.
return {
  -- First, we specify the Mason packages that should be installed.
  -- Mason is the tool manager that LazyVim uses.
  {
    "williamboman/mason.nvim",
    opts = {
      ensure_installed = { "clangd", "clang-format", "codelldb" },
    },
  },

  -- Next, we configure the LSP server itself.
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        -- The name of the server is 'clangd'
        clangd = {
          -- LazyVim will automatically set up the server with default options.
          -- We can add or override options here if we need to.
          -- For example, you could specify a specific command or arguments.
        },
      },
    },
  },

  -- Finally, we can add any extra plugins related to C/C++ development.
  -- For example, this plugin provides better syntax highlighting and other features.
  {
    "p00f/clangd_extensions.nvim",
  },
}
