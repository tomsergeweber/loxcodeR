% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plots.R
\name{readstats_plot_old}
\alias{readstats_plot_old}
\alias{readstats_plot_old,loxcode_experiment-method}
\title{Read stats plot}
\usage{
readstats_plot_old(
  x,
  count_matrix = "all_samples",
  code_set = "all_codes",
  plot = "size",
  fill = TRUE,
  labels = "sample"
)

\S4method{readstats_plot_old}{loxcode_experiment}(
  x,
  count_matrix = "all_samples",
  code_set = "all_codes",
  plot = "size",
  fill = TRUE,
  labels = "sample"
)
}
\arguments{
\item{x}{loxcode experiment object}

\item{count_matrix}{A matrix of the selected samples}

\item{code_set}{A matrix of the selected code sets}

\item{plot}{specify which plot (size/complexity/both/ratio)}

\item{fill}{specify whether reads should be normalized in boxplots}

\item{labels}{specify if graph should be labelled by sample name or alias}
}
\value{
A plot of the selected type explaing details of the samples
}
\description{
Generate size, complexity, both, ratio plot for the samples
}
\examples{
# Load required packages
library(loxcodeR)

# Example usage
# Assuming x, count_matrix, code_set, plot, fill, and labels are defined
datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
lox <- readRDS(datards)
readstats_plot_old(lox)
}
