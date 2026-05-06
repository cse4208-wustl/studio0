# Generating SSH Keys

When you connect to the school's servers with `ssh`, specify your username explicitly, for example:

```bash
ssh username@shell.cec.wustl.edu
```

If you connect with the wrong username or password repeatedly, your IP address may be blocked. Using an SSH key can help reduce password-entry mistakes.

## Generate a Key

1. Open a terminal on your computer.

2. Enter your local `.ssh` directory:

   ```bash
   cd .ssh
   ```

3. Generate a key:

   ```bash
   ssh-keygen -f your-key-name
   ```

   Replace `your-key-name` with a unique name such as `key_username`.

4. Enter a passphrase for the key when prompted.

Your key pair will be stored in two files:

- `your-key-name.pub`: your public key, which can be shared when needed
- `your-key-name`: your private key, which should never be shared

## Install the Key on the School Server

Run:

```bash
ssh-copy-id -i your-key-name your-username@shell.cec.wustl.edu
```

This associates the key with your account on the server. When prompted, enter your WUSTL Key password, not your SSH key passphrase.

### Windows Note

On some Windows setups, `ssh-copy-id` may not be available. In that case:

1. Copy the key files from your local `.ssh` directory to your `.ssh` directory on `shell.cec.wustl.edu` with `sftp`.
2. SSH into the server.
3. Enter the server-side `.ssh` directory:

   ```bash
   cd .ssh
   ```

4. Run the same `ssh-copy-id` command there if available, or otherwise finish the key setup using the server's SSH configuration tools.

If you copied your private key to the server temporarily, you may delete it from the server afterward.

## Configure Your SSH Client

If it does not already exist, create a file named `config` in your local `.ssh` directory and add:

```text
Host a-nickname-for-the-server
    HostName shell.cec.wustl.edu
    IdentityFile ~/.ssh/your-key-name
```

Choose any nickname you like for `a-nickname-for-the-server`, such as `shell`.

After this, you can connect with:

```bash
ssh a-nickname-for-the-server
```

or:

```bash
sftp a-nickname-for-the-server
```

You will be prompted for the SSH key passphrase you chose earlier.
