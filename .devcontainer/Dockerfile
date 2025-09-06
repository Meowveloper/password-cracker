# Base image
FROM gcc:15.2.0-trixie

# 1. Install system dependencies for Neovim, build tools, and our C LSP tools.
RUN apt-get update && apt-get install -y \
    git \
    lazygit \
    fzf \
    curl \
    neovim \
    libssl-dev \
    ripgrep && \
    rm -rf /root/.config/nvim && \
    mkdir -p /root/.config/nvim