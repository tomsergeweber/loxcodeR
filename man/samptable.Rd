% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/loxcode_experiment.R
\name{samptable}
\alias{samptable}
\alias{samptable,loxcode_experiment-method}
\title{Get sample table}
\usage{
samptable(x)

\S4method{samptable}{loxcode_experiment}(x)
}
\arguments{
\item{x}{loxcode object}
}
\value{
sample table
}
\description{
Get sample table
}
\examples{
# Example usage:
# Assuming 'lox_data' is a loxcode object
# Retrieve the sample table from the loxcode object
datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
lox <- readRDS(datards)
sample_table <- samptable(lox)
sample_table
}
