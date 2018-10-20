---
layout: post
title:  "using gitHub"
date:   2018-08-01 20:43:20 -0500
categories: class
---

## Using GitHub
## A Short Tutorial
___

First Step: Create a repository on GitHub. Make sure to initialize it with a readme.

After the repository has been created, you need to clone it on to your local computer.  We will refer to the repository created on Github and that lives on Github's servers at the _remote_ repository. The _local_ repository is what lives on your computer. We will make changes to the local repository and push these changes to the remote.  You will be able to share with your friends and colleagues what is posted on the remote repository through the miracle of the _World Wide Web_. They will be impressed.

I will discuss two options for for posting to and updating your GitHub repo.
1. Using the GitHub desktop client.
2. Using Terminal.

With both options we will be executing the following steps:
1. Clone:, cloning the remote repository to your local hard drive.
2. Stage ie. adding changes.
3. Commit: committing the changes.
4. Push: pushing your changes to the remote repository.
___

using the Desktop Client
___

__further reading__

[Desktop guides](https://help.github.com/desktop/guides/getting-started-with-github-desktop/)

Using Terminal
___
You will need to know some basic Terminal commands in order to update your remote repository through Terminal.  The most helpful ones will be::
```
pwd
ls
cd
```
To execute a command, type the command after the prompt ($) and hit `enter`.

`pwd` prints the current working directory, as in the directory you are in currently. When we issue commands the commands are enacted on that directory or the files in that directory.

`ls` lists the contents of the current directly.

`cd` changes the current working directory.

for example, to list the contents of my Documents folder i would need to type two commands
```
cd Documents
ls
```
I could then `cd` into another folder inside of Documents. To move back one directory, execute `cd ../`
No matter what directory you are currently in, you can execute only `cd` and you would move to your home directory.
Navigating in Terminal is a matter of `pwd`ing to see where you currently are, `ls`ing to see where you can go, `cd`ing deeper into a folder structure, and `cd ../`ing to back up.

You can also (and this you will most likely use), drag and drop a folder after typing `cd` to move directly to that directory.  Make sure you hit the spacebar after typing `cd` and before dropping the folder in.

__Cloning__

Open your Terminal app. `cd` to the directory in which you would like to put your git repository. To get the url for the remote repository click on the green 'Clone or download' button, then click on the clip board button inside of the drop down.
![super](../../../../blob/master/docs/_assets/gitClone.png)

Once there, type:

<pre><code>git clone <em>http-address-of-the-git-repo</em></code></pre>
and execute.

You now have a folder in that directory that is your copy of that repository.



__Staging__

Once you are done making changes to the repository you _stage_ your changes.

`cd` into the repository folder.
You can stage all changes at once with:
```
git add .
```
or you can stage one particular file with:

```
git add <i>name-of-file</i>
```

__Committing__

Once you are done adding all your changed to the staging "area" You can _commit_ your changes.
It is required to add a message when committing.
execute:

```
git commit -m "your-message"
```

If, when committing, you get a terminal screen that looks like:

```
# Please enter a commit message to explain why this merge is necessary,
# especially if it merges an updated upstream into a topic branch.
#
# Lines starting with '#' will be ignored, and an empty message aborts
# the commit.
~             
~
~
~
~
```

... it means that your git wants you to issue a commit message and the default terminal text editor is set to `vim`. `vim` is a powerful [text editor](http://www.openvim.com/), but not for the faint of heart. To exit out of that screen, you should use the following key sequence:

`ESCAPE`, `:`, `w`, `q`, `ENTER`

This will simply allow the merge to proceed with the default message.

If you would like to switch your default text editor to something simpler, like `nano`, configure git like this:

```
git config --global core.editor "nano"
```

If you'd like to use a GUI based text editor, you can use something like Atom.io by following [these instructions](https://stackoverflow.com/a/31389989/1518329).

__Pushing__

The last step is to _push_ your commits to the remote repository.

Execute:
```
git push
```

All the changes will be made visible on GitHub.

__further reading__

More gitHub resources

[GutHub Hello World](https://guides.github.com/activities/hello-world/)

[GitHub cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)
