% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plots.R
\name{readstats_plot2}
\alias{readstats_plot2}
\alias{readstats_plot2,loxcode_experiment-method}
\title{readstats plot}
\usage{
readstats_plot2(
  loxcode_experiment,
  count_matrix = "all_samples",
  code_set = "all_codes",
  plot = "size",
  fill = TRUE,
  labels = "alias"
)

\S4method{readstats_plot2}{loxcode_experiment}(
  loxcode_experiment,
  count_matrix = "all_samples",
  code_set = "all_codes",
  plot = "size",
  fill = TRUE,
  labels = "sample"
)
}
\arguments{
\item{loxcode_experiment}{loxcode_experiment object}

\item{count_matrix}{A matrix of the selected samples}

\item{code_set}{A matrix of the selected code sets}

\item{plot}{specify which plot (size/complexity/both/ratio)}

\item{fill}{specify whether reads should be normalized in boxplots}

\item{labels}{labels to use in the plot}
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
# Assuming loxcode_experiment, count_matrix, code_set, plot, fill, and labels are defined
datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
lox <- readRDS(datards)
readstats_plot2(lox)
}
