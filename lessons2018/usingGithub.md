---
layout: page
title: using GitHub
# permalink: /00a/
---

## Using GitHub to upload your work
## A Short Tutorial

v6.
___

First Step: Create a repository on GitHub. Make sure to initialize it with a readme.

After the repository has been created, you need to clone it on to your local computer.  We will refer to the repository created on Github and that lives on Github's servers at the _remote_ repository. The _local_ repository is what lives on your computer. We will make changes to the local repository and push these changes to the remote.  You will be able to share with your friends and colleagues what is posted on the remote repository through the miracle of the _World Wide Web_. They will be impressed.

I will discuss two options for for posting to and updating your GitHub repo.
1. Using the GitHub desktop client.
2. Using Terminal.

With both options we will be executing the following steps:
1. Clone:cloning the remote repository to your local hard drive.
2. Stage ie. adding changes.
3. Commit: committing the changes.
4. Push: pushing your changes to the remote repository.

___
using the Desktop Client

___

If you haven't already done so, download the GitHub desktop client. From [here](https://desktop.github.com/).

__Cloning__

Clone your remote repository. In this example, I am cloning my repository interactive-art-code that I created on gitHub.

Open up the desktop client. Go to File-> Clone Repository...

![super1](https://github.com/ajbajb/ARTTECH3135-fall2018/blob/master/lessons2018/asset/images/dc1.png)

Choose the repository you wish to clone, in this case I am cloning ajbajb/interactive-art-code.  By default, Github will put the cloned repo in a folder called Github.  You can choose another path if you want or just hit the blue "Clone" button.  

![super2](../../blob/master/lessons2018/asset/images/dc2.png)

Navigate to the location of the cloned repository. Add the files you wish to upload. I recommend copying files and folders into the repository. Have a look at [this](https://ajbajb.github.io/ARTTECH3135-fall2018/class/2018/10/18/class07.html) for a suggestion on how to organize the folders in the repository.

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc3.png){:height="200px"} -->

After you have finished adding and making changes to the repo, go back to the Desktop client. In the top left corner of the client, the Current Repository should be your interactive-art-code repo.

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc4-1.png){:height="200px"} -->

__Staging__

Along the left side of the client it will list all the files you added and changes that you made to the repository. Make sure the small box next to each change has a checkmark (everything should be checked by default).  This represents your staged changes.

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc5.png){:height="200px"} -->

__Committing__

If everything looks good, you can commit these changes.
    Add a quick summary in the dialogue box. A summary is required to commit the changes, but a description is not.

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc6.png){:height="200px"}
![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc6-1.png){:height="200px"} -->

After you are done writing a short summary, click the blue 'Commit to master' button.

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc7.png){:height="200px"} -->

__Pushing__
After you commit, the last step is to push the changes to the remote repository.  Click on the big 'Push origin' button near the top of the client or go to Repository-> Push.

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc8.png){:height="200px"}
![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/dc8-1.png){:height="200px"} -->
___

__further reading__

[Desktop guides](https://help.github.com/desktop/guides/getting-started-with-github-desktop/)

___

__Using Terminal__

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

<!-- ![super]({{site.url}}/ARTTECH3135-fall2018/assets/images/gitClone.png) -->

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
# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
#
# On branch master
# Your branch is up to date with 'origin/master'.
#
~             
~
~
~
~
```

... it means that your git wants you to issue a commit message and the default terminal text editor is set to `vim`. `vim` is a powerful [text editor](http://www.openvim.com/), but not for the faint of heart. To exit out of that screen, you should use the following key sequence:

`ESCAPE`, `:`, `w`, `q`, `ENTER`

This will simply abort the commit so that you can try `git commit -m` again.

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
