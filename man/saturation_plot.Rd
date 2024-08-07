% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plots.R
\name{saturation_plot}
\alias{saturation_plot}
\alias{saturation_plot,loxcode_experiment-method}
\title{Plotting the saturation of samples}
\usage{
saturation_plot(loxcode_experiment, loxcode_sample, code_set = "all_codes")

\S4method{saturation_plot}{loxcode_experiment}(loxcode_experiment, loxcode_sample, code_set = "all_codes")
}
\arguments{
\item{loxcode_experiment}{loxcode_experiment object}

\item{loxcode_sample}{A matrix of the selected samples}

\item{code_set}{A matrix of the selected code sets}
}
\value{
Saturation plot of the loxcode sample
}
\description{
Plotting the saturation of samples
}
\examples{
# Load required packages
library(loxcodeR)

# Example usage
# Assuming loxcode_experiment, loxcode_sample, and code_set are defined
datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
lox <- readRDS(datards)
saturation_plot(lox,"N712_N501")
}
