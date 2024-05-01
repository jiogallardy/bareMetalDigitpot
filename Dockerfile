# Use an official Ruby runtime as a parent image
FROM ruby:2.7

# Set the working directory in the container
WORKDIR /usr/src/app

# Install Ceedling
RUN gem install ceedling

# Jump right in
CMD ["/bin/bash"]
