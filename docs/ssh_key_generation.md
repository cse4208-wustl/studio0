# Generating SSH Keys

When you connect to the school's servers with `ssh`, you must specify your username explicitly:

```
ssh username@shell.cec.wustl.edu
```

If you connect with the wrong username or password repeatedly, your IP address may be blocked. Setting up an SSH key lets you connect without entering your password each time.

## Generate a Key

1. Open a terminal on your computer.

2. Run the following command to generate a key pair, replacing `your-key-name` with a descriptive name such as `key_username`:

   ```
   ssh-keygen -t ed25519 -f ~/.ssh/your-key-name
   ```

   This creates two files in your `~/.ssh/` directory:
   - `your-key-name.pub` — your **public** key, which can be shared
   - `your-key-name` — your **private** key, which should **never** be shared

3. When prompted for a passphrase, you may either:
   - Press **Enter** twice to skip the passphrase (simplest — no password ever required), or
   - Enter a passphrase for added security (you will be prompted for it each time you connect, unless you set up `ssh-agent`)

## Install the Key on the School Server

Run:

```
ssh-copy-id -i ~/.ssh/your-key-name.pub your-username@shell.cec.wustl.edu
```

When prompted, enter your **WUSTL Key password** (not your SSH key passphrase). This copies your public key to the server so it can recognize you.

### Windows Note

On some Windows setups, `ssh-copy-id` may not be available. In that case, run the following in either PowerShell or Command Prompt:

```
type $env:USERPROFILE\.ssh\your-key-name.pub | ssh your-username@shell.cec.wustl.edu "cat >> ~/.ssh/authorized_keys"
```

> **Note:** Only your **public** key (`.pub` file) should ever be copied to the server. Never copy your private key to any remote machine.

## Configure Your SSH Client

Create or edit the file `~/.ssh/config` on your local machine and add the following, replacing the placeholder values:

```
Host shell
    HostName shell.cec.wustl.edu
    User your-username
    IdentityFile ~/.ssh/your-key-name
```

You can choose any nickname you like in place of `shell`.

If you created this file for the first time, set the correct permissions:

```
chmod 700 ~/.ssh
chmod 600 ~/.ssh/config
```

After this, you can connect with simply:

```
ssh shell
```

or transfer files with:

```
sftp shell
```

## Verify It Works

After completing the steps above, run:

```
ssh shell
```

If everything is set up correctly, you will connect without being asked for your WUSTL password. If you set a passphrase in step 3, you will be prompted for that instead.
