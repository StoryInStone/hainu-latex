\ProvidesClass{application}[2014/03/04 v1.0 Simple application class]
\LoadClass{article}

\RequirePackage[T1]{fontenc}
\RequirePackage{lmodern}
\renewcommand*\familydefault{\sfdefault}
\RequirePackage{sfmath}
\RequirePackage{microtype}
\RequirePackage[utf8]{inputenc}

\usepackage{cfr-lm}

\RequirePackage{listings}
\lstset{language=java}

\RequirePackage[ngerman]{babel}
%\RequirePackage[english]{babel}
%\selectlanguage{english}
%\selectlanguage{german}
\RequirePackage[margin=2cm,a4paper]{geometry}

\RequirePackage{graphicx}
\graphicspath{{./}{../}{images/}}


\renewcommand{\baselinestretch}{1.1}
\setlength{\parindent}{0pt}
%\setlength{\parskip}{5pt}

\newcommand{\titleabstand}{\hspace{3cm}}
\newcommand{\RNum}[1]{\uppercase\expandafter{\romannumeral #1\relax}}

%重定义制作封面命令
\renewcommand{\maketitle}{
\begin{titlepage}
\thispagestyle{empty}

%页面中的logo
\begin{minipage}[t]{1.0\textwidth}
\vspace{-1.7cm}
\hfill
\includegraphics[scale=0.23]{images/logo-name.png}
\end{minipage}

%文章标题
\begin{minipage}{\textwidth}
    \ \\
    \vspace{0.5cm}
    \ \\
    \begin{minipage}[t]{1.0\textwidth}
        \begin{flushright}
        \Large{数据结构课程设计论文}\\
        \Huge{基于最小生成树的股票分层工具\\——以沪深300为例}\\
        \Large 2015.12.11
        \end{flushright}
    \end{minipage}
\end{minipage}

%页面中间空白
\hspace{3cm}
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak
\linebreak

%作者信息右
\Large
\begin{flushright}
卢俊星\\
海南大学\\
\href{mailto:StoryInStone@outlook.com}{StoryInStone@outlook.com}\\
\url{https://github.com/StoryInStone}\\
\end{flushright}

%作者信息左
\vspace{-0.9cm}
\begin{flushleft}
通信工程\\
20120802310083
\end{flushleft}

\end{titlepage}
%封面制作完成
}
