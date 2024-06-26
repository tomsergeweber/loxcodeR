% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/loxcode_experiment.R
\docType{class}
\name{loxcode_experiment-class}
\alias{loxcode_experiment-class}
\alias{loxcode_experiment}
\title{Loxcode experiment object}
\value{
Loxcode experiment object
}
\description{
The `loxcode_experiment` object enables handling of data from multiple samples.
}
\section{Slots}{

\describe{
\item{\code{name}}{string, name of the experiment}

\item{\code{dir}}{string, directory containing R1, R2 *.fastq files. Must end with '/'}

\item{\code{samples}}{list, contains loxcode_sample objects that can be accessed by the sample name}

\item{\code{samp_table}}{data.frame, user-specified table that can be loaded from an Excel spreadsheet}

\item{\code{count_matrixes}}{, has barcode counts for all samples}

\item{\code{code_sets}}{, has code sets generated by filtering, by default contains all codes in all samples}
}}

