# Setting Up SSH Keys for Git

## What Are SSH Keys?

SSH keys come in pairs: a **private key** (stays on your machine, never shared) and a **public key** (you give this to GitHub/GitLab). When you connect, the server challenges your client to prove it has the private key — no password needed. It's both more secure and more convenient than passwords/tokens.

---

## Step 1: Generate a Key Pair

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```

- `-t ed25519` specifies the algorithm (ed25519 is modern and recommended)
- `-C` adds a comment to help identify the key later
- When prompted for a save location, press **Enter** to accept the default (`~/.ssh/id_ed25519`)
- When prompted for a passphrase, press **Enter** to skip (no passphrase)

---

## Step 2: Add the Public Key to GitHub

Print your public key:

```bash
cat ~/.ssh/id_ed25519.pub
```

Copy the output, then:

1. Go to **GitHub → Settings → SSH and GPG keys**
2. Click **New SSH key**
3. Give it a title (e.g. "My Linux Server")
4. Paste your public key and save

---

## Step 3: Test the Connection

```bash
ssh -T git@github.com
```

If everything is set up correctly, you'll see:

```
Hi username! You've successfully authenticated, but GitHub does not provide shell access.
```

---

## Step 4: Clone a Repo Using SSH

On your repository's GitHub page, click the **Code** button and select the **SSH** tab to get the SSH URL. Then clone it:

```bash
git clone git@github.com:username/repo.git
```

From this point on, all `git push` and `git pull` commands will authenticate automatically using your SSH key — no username or token prompts.

